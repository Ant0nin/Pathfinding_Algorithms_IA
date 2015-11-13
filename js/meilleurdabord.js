//meilleur d'abord

function MeilleurDabord(etatinitial,op){
	//op array list des operateurs
	//op g=4 h=8 d=6 b=2

	pile = new Pile();

	pile.insert(etatinitial,etatinitial.heurist);

	while(pise.lentgh !=0){

		curNoeud = pile.pick();

		if( curNoeud.sucesseur == 0){//test but ?
			return curNoeud;
		} 

		else{
			listEnfant = [op.lentgh];
			for(var i=0; i<op.lentgh; i++){
				curNoeudEnfant = sucesseur(curNoeud,op[i]);
				if(valide(curNoeudEnfant)){
					//pile.insert(curNoeudEnfant,heurist(curNoeudEnfant));
					listEnfant.push(curNoeudEnfant);
				}
			}
			listEnfant.sort(triPile);
			pile = pile.join(listEnfant);
		}
	}

	return null;
}



function Pile() {
	this.array = [];
};

function Noeud(x,y){
	this.x = x;
	this.y = y;
	this.h=0;
	
}

Noeud.prototype.determinerHeuristique() = function(){
	this.h = 5;
}

function sucesseur (noeud,op){
	var sucNoeud = new Noeud(noeud.x,noeud.y);

	switch(op){

		case 4 : 
		sucNoeud.x -=1;
		break;
		
		case 6 : 
		sucNoeud.x +=1;
		break;
		
		case 8 : 
		sucNoeud.y -=1;
		break;
		
		case 2 : 
		sucNoeud.y +=1;
		break;
	}

	noeud.determinerHeuristique();

}



function triPile(noeudA,noeudB){
	return noeudA.heur - noeudB.heur;
}

function valide(noeud){
	if(labyrinthe[noeud.x][noeud.y] !=1 ) return false;
	else return true;
}

