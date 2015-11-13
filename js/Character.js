var Character = function(x, y) {
	this.x = x;
	this.y = y;
}

Character.prototype.moveTo(x, y) {
	this.x = x;
	this.y = y;
}

Character.prototype.getPos() {
	return {
		x: this.x,
		y: this.y
	}
}