import React from 'react';

export default function WeclomeMessage() {
  const containerStyle = {
    textAlign: 'center',
    marginTop: '50px',
    fontFamily: 'Arial, sans-serif',
  };
  const handleClick = () => {
    alert('Thanks for Clicking');
  };
  return (
    <div style={containerStyle}>
      <h1>Weclome to React</h1>
      <p>I am Glad to be Here</p>
      <button onClick={handleClick}>Click Me</button>
    </div>
  );
}
