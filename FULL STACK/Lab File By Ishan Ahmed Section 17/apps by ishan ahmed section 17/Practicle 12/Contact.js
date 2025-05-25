import React from 'react';
import { useNavigate } from 'react-router-dom';
export default function Contact() {
  const navigate = useNavigate();
  return (
    <div>
      <h2>This is the Contact Us Page</h2>
      <button onClick={() => navigate('/user')}>Home</button>
      <button onClick={() => navigate('/about')}>About</button>
      <button onClick={() => navigate('/')}>Sign Out</button>
    </div>
  );
}
