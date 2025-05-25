import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function Login() {
  const [name, setName] = useState('');
  const [password, setPassword] = useState('');
  const navigate = useNavigate();

  const handleLogin = (e) => {
    e.preventDefault();
    if (name.trim() && password.length >= 8) {
      navigate('/user', { state: { name: name.trim() } });
    }
  };

  return (
    <div>
      <form onSubmit={handleLogin}>
        <h2>Login Page</h2>

        <div>
          <input
            value={name}
            onChange={(e) => setName(e.target.value)}
            placeholder="Enter your name"
            required
          />
        </div>

        <div>
          <input
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            placeholder="Enter Password"
            required
          />
        </div>

        <button
          type="submit"
          disabled={!name.trim() || password.length < 8}
          style={{
            color: 'Black',
            backgroundColor: 'skyblue',
            fontWeight: 'bold',
          }}
        >
          LOGIN
        </button>
      </form>
    </div>
  );
}
