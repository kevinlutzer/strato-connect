/*
    Creates labels for the diode ring modulator pcb

    Author: Kevin Lutzer
    Date: June 13 2023
*/

// generates a rounded box with some text in the center
module generateLabel(width, height, radius, label, ts) {
    $fn=40;

    difference() {
        translate([- width / 2, - height / 2]) {
            minkowski() {
              square([width, height]);
              circle(r=radius);
            }
        }

        text(label, font="Liberation SansL:style=Bold", valign="center", halign="center", size=ts);        
    }

            
}

module generatePinHeader(width, height, radius, ts, labels, pin_pitch=2.54) {
    $fn=40;

    difference() {
        translate([- width / 2, - height / 2]) {
            minkowski() {
              square([width, height]);
              circle(r=radius);
            }
        }
        
        labels_len = len(labels);
        for (i = [0:1:len(labels)]) {
            label = labels[len(labels) - 1 - i];
            translate([-width/2, - (pin_pitch * labels_len)/2 + pin_pitch*i + pin_pitch / 2 ])
                text(label, font="Liberation Sans:style=Bold", valign="center", halign="left", size=ts);
        }
                        
    }            
}


//generatePinHeader(3.75, 4, 0.25, 1.2, ["TX", "GND", "RX"], 1.25); // UART header
//generatePinHeader(3.75, 6, 0.25, 1.2, ["GND", "VIN", "SDA", "SCL", "INT"], 1.25); // UART header
//generatePinHeader(3.75, 4, 0.25, 1.2, ["GND", "VIN"], 2.54); // Power header
//generateLabel(11.5, 1.75, 0.25, "StratoConnect", 1.2);
//generateLabel(5, 1.75, 0.25, "Rev 1", 1.2);
//generateLabel(6, 1.75, 0.25, "VIN=5V", 1.2);
//generateLabel(17.5, 1.75, 0.25, "Bypass Level Shifting", 1.2);
//generateLabel(4.5, 1.75, 0.25, "TRIG", 1.2);
//generateLabel(3.75, 1.75, 0.25, "RST", 1.2);
generatePinHeader(2.5, 4, 0.25, 1.2, ["TX", "RX"], 2.54); // Power header
