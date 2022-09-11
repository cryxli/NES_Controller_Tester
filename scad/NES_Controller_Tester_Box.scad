// -------------------------------------------------
// NES Controller Tester
// by cryxli, August 2022
// -------------------------------------------------

base_plate = 2;     // [mm] How strong to make the bottom of the box
depth = 25;         // [mm] How far the socket raches into the box
height = 17;        // [mm] Height of the socket
oled_width = 19.5;  // [mm] Height of the OLED display
oled_length = 33.5; // [mm] Length of the OLED display
$fn = 18;           // [faces] Make circles 18 sided polys

// The body of the box
difference() {
	union() {
		// base
		cube([36,depth+48+2+5,base_plate]);
		
		// left side of socket
		cube([5.5,2.5,base_plate+height]);
		cube([2.5,10,base_plate+height]);
		translate([0,5,0]) cube([5.5,depth-5,base_plate+height]);
		translate([0,14.5,0]) cube([9.5,depth-14.5,base_plate+height]);

		// right side of socket
		translate([30.5,0,0]) {
			cube([5.5,2.5,base_plate+height]);
			translate([3,0,0]) cube([2.5,10,base_plate+height]);
			translate([0,5,0]) cube([5.5,depth-5,base_plate+height]);
			translate([-4,14.5,0]) cube([9.5,depth-14.5,base_plate+height]);
		}

		// bottom support for socket
		translate([0,14.5,0]) cube([36,depth-14.5,base_plate+4]);
		
		// back of box
		translate([0,depth+53,0]) cube([36,2,base_plate+height]);
		translate([0,depth+48,0]) cube([7,7,base_plate+height]);
		translate([29,depth+48,0]) cube([7,7,base_plate+height]);
		
		// sides
		cube([2,depth+48+2+5,base_plate+height-3.5]);
		translate([34,0,0]) cube([2,depth+48+2+5,base_plate+height-3.5]);
	}

	// M3 holes behind the socket
	translate([5,depth-4.75,-1]) cylinder(d=3, h=base_plate+height+2);
	translate([31,depth-4.75,-1]) cylinder(d=3, h=base_plate+height+2);
	// M3 holes at the end of the box
	translate([2+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=base_plate+height+2);
	translate([31+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=base_plate+height+2);
	
	// slit for USB lead
	translate([(36-3)/2,depth+48+2+5-3,height/2]) cube([3,4,height]);
}


// The lid
translate([40,0,0]) difference() {
	union() {
		// base
		cube([36,depth+48+2+5,3]);
		// register and hold-down for socket
		translate([(36-17)/2,15,0]) cube([17,8,3+4]);
		// with register for ESP
		translate([(36-17)/2,15,0]) cube([17,10,3+2]);
		
		// interlocking sides (0.5mm gap is intentional)
		translate([0,depth,0]) cube([2,48,6]);
		translate([36-2,depth,0]) cube([2,48,6]);
	}
	// space for the micro USB connector and buttons
	translate([(36-oled_width)/2,depth+48+5-12,2]) cube([oled_width,10,2]);
	
	// hole for OLED display and its ribbon
	translate([(36-oled_width)/2,depth,-1]) cube([oled_width,oled_length,5]);
	translate([(36-oled_width)/2+oled_width-1,depth + (oled_length-13)/2,-1]) cube([3,13,5]);
	
	// M3 holes behind the socket
	translate([5,depth-4.75,-1]) cylinder(d=3, h=5);
	translate([31,depth-4.75,-1]) cylinder(d=3, h=5);
	// M3 holes at the end of the box
	translate([2+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=5);
	translate([31+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=5);
}

