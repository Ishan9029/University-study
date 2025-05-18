import React from 'react';
import { useParams, useNavigate } from 'react-router-dom';

export default function User() {
  const navigate = useNavigate();
  const { username } = useParams();
  return (
    <div>
      <h2>Welcome, {username}!</h2>
      <button onClick={() => navigate('/Login')}>Go to Login Page</button>
    </div>
  );
}
