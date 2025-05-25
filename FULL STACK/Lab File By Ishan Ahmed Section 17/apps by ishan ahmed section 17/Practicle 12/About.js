import React from 'react';
import { useNavigate } from 'react-router-dom';
export default function About() {
  const navigate = useNavigate();
  return (
    <div>
      <h2>This is the About Page</h2>
      <button onClick={() => navigate('/user')}>Home</button>
      <button onClick={() => navigate('/contact')}>Contact</button>
      <button onClick={() => navigate('/')}>Sign Out</button>
    </div>
  );
}
