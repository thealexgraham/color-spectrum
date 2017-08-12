(
p = SerialPort(
    "/dev/tty.Arduino-DevB",    //edit to match your port. SerialPort.listDevices
    baudrate: 9600,    //check that baudrate is the same as in arduino sketch
    crtscts: true);
)

p.putAll("1");
{
	p.next.postln;
	p.put(1.asInteger);
	p.next.postln;
}
//send serial data - slow pulsating
(
r= Routine({
    inf.do{|i|
        p.putAll("0");
        0.1.wait;
		p.putAll("1");
    };
}).play;
)

r.stop;
p.close;

{
	SerialPort.listDevices
}