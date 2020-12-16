class Vec2 {
public:
	float x;
	float y;
public:
	Vec2(float x,float y) {
		this->x = x;
		this->y = y;
	}
};

class Line {
public:
	Vec2 p1,p2;
public:
	Line(Vec2 a,Vec2 b):p1(a),p2(b) {

	}
};

bool lx(Line a, Line b) {
	if (
		((a.p1.y - a.p2.y) * (b.p1.x - a.p1.x) + (a.p1.x - a.p2.x) * (a.p1.y - b.p1.y))
		* ((a.p1.y - a.p2.y) * (b.p2.x - a.p1.x) + (a.p1.x - a.p2.x) * (a.p1.y - b.p2.y)) < 0
		&&
		((b.p1.y - b.p2.y) * (a.p1.x - b.p1.x) + (b.p1.x - b.p2.x) * (b.p1.y - a.p1.y))
		* ((b.p1.y - b.p2.y) * (a.p2.x - b.p1.x) + (b.p1.x - b.p2.x) * (b.p1.y - a.p2.y)) < 0
		) {
		return true;
	}
	else {
		return false;
	}
}

Vec2 Line_Vec(Line a) {
	return Vec2(a.p2.x - a.p1.x, a.p2.y - a.p1.y);
}

Vec2 normal(Vec2 a) {
	float lenght = a.x * a.x + a.y * a.y;
	return Vec2(a.x / lenght, a.y / lenght);
}

Vec2 Dot_zero(Vec2 a) {
	return Vec2(-a.y, a.x);
}

void Cross_Line(Line a, Line b, bool* TF, Vec2* p) {
	Vec2 output(0.0f,0.0f);

	if (!lx(a, b)) {
		*TF = false;
		*p = output;
		return;
	}
	float	Sa = ((b.p2.x - b.p1.x) * (a.p1.y - b.p1.y) - (b.p2.y - b.p1.y) * (a.p1.x - b.p1.x)) / 2.0f,
			Sb = ((b.p2.x - b.p1.x) * (b.p1.y - a.p2.y) - (b.p2.y - b.p1.y) * (b.p1.x - a.p2.x)) / 2.0f;
	output.x = a.p1.x + (a.p2.x - a.p1.x) * Sa / (Sa + Sb);
	output.y = a.p1.y + (a.p2.y - a.p1.y) * Sa / (Sa + Sb);

	*TF = true;
	*p = output;
	return;
}

void Cross_Line_h(Line d_l, Line b, bool* TF, Vec2* p) {
	Vec2 output(0.0f, 0.0f);
	Vec2 p_(0.0f, 0.0f);
	Cross_Line(d_l, b, TF, &p_);
	if (!TF) {
		return;
	}
	output.x = p_.x + (b.p2.x - b.p1.x) * ((d_l.p2.x - p_.x) * (b.p2.x - b.p1.x) + (d_l.p2.y - p_.y) * (b.p2.y - b.p1.y)) / ((b.p2.x - b.p1.x) * (b.p2.x - b.p1.x)+ (b.p2.y - b.p1.y) * (b.p2.y - b.p1.y));
	output.y = p_.y + (b.p2.y - b.p1.y) * ((d_l.p2.x - p_.x) * (b.p2.x - b.p1.x) + (d_l.p2.y - p_.y) * (b.p2.y - b.p1.y)) / ((b.p2.x - b.p1.x) * (b.p2.x - b.p1.x) + (b.p2.y - b.p1.y) * (b.p2.y - b.p1.y));
	
	output.x -= Dot_zero(normal((Line_Vec(b)))).x;
	output.y -= Dot_zero(normal((Line_Vec(b)))).y;

	*p = output;
	return;
}