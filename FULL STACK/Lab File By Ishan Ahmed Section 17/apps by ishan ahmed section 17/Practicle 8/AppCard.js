import React from 'react';
import Card from './Card';

export default function AppCard() {
  return (
    <div style={{ backgroundColor: 'red', fontFamily: 'cursive' }}>
      <Card
        title="My Card"
        description="This is What I Can Do Myself"
        fontcolor="blue"
      />
    </div>
  );
}
