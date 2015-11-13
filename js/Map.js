"use strict";

class Map extends canvas.Scene {
	
	constructor() {
		super(arguments);
		this.name = "defaultLevel";
	}
	
	new(config) {
		super.new(config);
		
		var mapFile = document.getElementById("levelSelector").files[0];
		var reader = new FileReader();
	
		reader.onload = this.load;
		
		reader.readAsText(mapFile);
	}
	
	load(e) {
		
		data = e.target.result.split("\n");
		var x = data[0];
		var y = data[1];
		var w = data[2];
		var h = data[4];
	}
	
}