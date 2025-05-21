import React from 'react';
import { useNavigate, useLocation } from 'react-router-dom';

export default function User() {
  const navigate = useNavigate();
  //const { username } = useParams();
  const location = useLocation();
  const name = location.state?.name || 'Ishan';
  return (
    <div>
      <h2>Welcome, {name}!</h2>
      <button onClick={() => navigate('/about')}>About</button>
      <button onClick={() => navigate('/contact')}>Contact</button>
      <button onClick={() => navigate('/')}>Sign Out</button>
    </div>
  );
}
