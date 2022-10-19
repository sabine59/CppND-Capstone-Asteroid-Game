#include "celestrial_body.h"

CelBody::~CelBody() {};


void CelBody::UpdatePosition() {
   rect.x -= _velocity_x;
   rect.y += _velocity_y;
}

