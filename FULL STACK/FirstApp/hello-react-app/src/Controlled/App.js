import React, { useState } from 'react';

export default function MyForm() {
  const [name, setName] = useState('');

  const handleSubmit = (event) => {
    event.preventDefault();
    alert(`Submitted name: ${name}`);
  };

  return (
    <form onSubmit={handleSubmit}>
      <label>Username</label>
      <br />
      <input type="text" onChange={(e) => setName(e.target.value)} required />
      <br />
      <button type="submit">Submit</button>
    </form>
  );
}
