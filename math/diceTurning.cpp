// how to represent the turning dice?
// O(1)

struct DICE{
	int t, d, f, r, b, l;// someone use bad naming XD
	bool operator == (const DICE& right)const{// maybe different
		if(t != right.t) return false;
		if(d != right.d) return false;
		if(f != right.f) return false;
		if(r != right.r) return false;
		if(b != right.b) return false;
		if(l != right.l) return false;
		return true;
	}
	bool operator < (const DICE& right)const{// check it carefully
		if(t != right.t) return t < right.t;
		if(f != right.f) return f < right.f;
		if(r != right.r) return r < right.t;
		if(b != right.b) return b < right.b;
		if(l != right.l) return l < right.l;
		return d < right.d;
	}

};

DICE turn(DICE dice, string way){
	if(way == "north"){
		swap(dice.d, dice.f);
		swap(dice.f, dice.t);
		swap(dice.t, dice.b);
	}
	else if(way == "east"){
		swap(dice.d, dice.r);
		swap(dice.t, dice.r);
		swap(dice.t, dice.l);
	}else if(way == "south"){
		swap(dice.t, dice.b);
		swap(dice.t, dice.f);
		swap(dice.f, dice.d);
	}else if(way == "west"){
		swap(dice.t, dice.l);
		swap(dice.t, dice.r);
		swap(dice.r, dice.d);
	}
	return dice;
}
