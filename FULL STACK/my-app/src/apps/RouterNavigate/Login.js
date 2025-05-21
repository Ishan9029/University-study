import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function Login() {
  const [name, setName] = useState('');
  const navigate = useNavigate();

  return (
    <div>
      <h2>Login Page</h2>
      <input
        value={name}
        onChange={(e) => setName(e.target.value)}
        placeholder="Enter your name"
      />
      <button
        disabled={!name.trim()}
        onClick={() => navigate('/user', { state: { name: name.trim() } })}
        style={{
          color: 'Black',
          backgroundColor: 'skyblue',
          fontWeight: 'bold',
        }}
      >
        LOGIN
      </button>
    </div>
  );
}
