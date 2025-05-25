import React from 'react';

export default function Card({ title, description, fontcolor, background }) {
  const cardStyle = {
    border: '1px solid #ccc',
    padding: '10px',
    margin: '10px',
    color: fontcolor,
    backgroundColor: background || 'white',
  };

  const titleStyle = {
    fontSize: '1.2em',
    fontWeight: 'bold',
    marginBottom: '8px',
  };

  return (
    <div style={cardStyle}>
      <h3 style={titleStyle}>{title}</h3>
      <p>{description}</p>
    </div>
  );
}
