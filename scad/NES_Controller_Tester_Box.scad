
// box
base_plate = 2;
stud = 6;
depth = 25;
height = 17;

diam = 3.5;
$fn = 18;


difference() {
	union() {
		cube([36,depth+48+2+5,base_plate]);
		
		translate([0,depth+53,0]) cube([36,2,base_plate+height]);
		translate([0,depth+48,0]) cube([7,7,base_plate+height]);
		translate([29,depth+48,0]) cube([7,7,base_plate+height]);
		
		cube([5.5,2.5,base_plate+height]);
		cube([2.5,10,base_plate+height]);
		translate([0,5,0]) cube([5.5,depth-5,base_plate+height]);
		translate([0,14.5,0]) cube([9.5,depth-14.5,base_plate+height]);
		
		translate([30.5,0,0]) {
			cube([5.5,2.5,base_plate+height]);
			translate([3,0,0]) cube([2.5,10,base_plate+height]);
			translate([0,5,0]) cube([5.5,depth-5,base_plate+height]);
			translate([-4,14.5,0]) cube([9.5,depth-14.5,base_plate+height]);
		}
		
		translate([0,14.5,0]) cube([36,depth-14.5,base_plate+4]);
		
		cube([2,depth+48+2+5,base_plate+height-3.5]);
		translate([34,0,0]) cube([2,depth+48+2+5,base_plate+height-3.5]);
	}
	translate([5,depth-4.75,-1]) cylinder(d=3, h=base_plate+height+2);
	translate([31,depth-4.75,-1]) cylinder(d=3, h=base_plate+height+2);
	
	translate([2+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=base_plate+height+2);
	translate([31+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=base_plate+height+2);
	//translate([(36-11)/2,depth+48+5-1,base_plate+height-3]) cube([11,4,4]);
	
	translate([(36-3)/2,depth+48+2+5-3,height/2]) cube([3,4,height]);
}


//lid
oled_width = 19.5;
oled_length = 33.5;

translate([40,0,0]) difference() {
	union() {
		cube([36,depth+48+2+5,3]);
		translate([(36-17)/2,15,0]) cube([17,8,3+4]);
		translate([(36-17)/2,15,0]) cube([17,10,3+2]);
		
		translate([0,depth,0]) cube([2,48,6]);
		translate([36-2,depth,0]) cube([2,48,6]);
	}
	translate([(36-oled_width)/2,depth+48+5-12,2]) cube([oled_width,10,2]);
	
	//translate([(36-8)/2,depth+48+5-12,2]) cube([8,12+3,2]);
	//translate([(36-11)/2,depth+48+5-4,-1]) cube([11,7,5]);
		
	translate([(36-oled_width)/2,depth,-1]) cube([oled_width,oled_length,5]);
	translate([(36-oled_width)/2+oled_width-1,depth + (oled_length-13)/2,-1]) cube([3,13,5]);

	
	translate([5,depth-4.75,-1]) cylinder(d=3, h=5);
	translate([31,depth-4.75,-1]) cylinder(d=3, h=5);

	translate([2+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=5);
	translate([31+1.5,depth+48+2+1.5,-1]) cylinder(d=3, h=5);
}

