import React from 'react';
import { useParams, useNavigate, useLocation } from 'react-router-dom';

export default function User() {
  const navigate = useNavigate();
  const { username } = useParams();
  const location = useLocation();
  const name = location.state?.name || 'Guest';
  return (
    <div>
      <h2>Welcome, {name}!</h2>
      <button onClick={() => navigate('/')}>Go to Login Page</button>
    </div>
  );
}
