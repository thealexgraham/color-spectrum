
(
MIDIClient.init;
~mout = MIDIOut.newByName("Launchkey MK2 61", "Launchkey InControl");
~m1   = MIDIOut.newByName("to Max 1", "to Max 1");
MIDIIn.connectAll;
)

MIDIClient.destinations;

m.noteOn(15, rrand(36,51), rrand(1,127));
MIDIIn.connectAll

(
MIDIdef.noteOn(\random, {|val, num, chan, src|
	chan.postln;
	~mout.noteOn(2, rrand(36,51), rrand(1,127));
	~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
			~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
		~mout.noteOn(2, rrand(36,51), rrand(1,127));
	~m1.control(0,num,chan);

}, nil, nil);
)

(
MIDIdef.noteOn(\randomOff, {|vel, num, t|
	num.postln;
	//~mout.noteOff(15, rrand(36,51), 0);

});
)

MIDIdef.freeAll


m.port
(

//m.noteOn(16, 61, 60);
//m.noteOff(16, 61, 60);
m.allNotesOff(16);
)