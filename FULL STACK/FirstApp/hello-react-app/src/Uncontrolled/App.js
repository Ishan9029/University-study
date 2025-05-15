import React, { useRef } from 'react';

export default function MyForm() {
  const nameRef = useRef(null);

  const handleSubmit = (event) => {
    event.preventDefault();
    alert(`Submitted name: ${nameRef.current.value}`);
  };

  return (
    <form onSubmit={handleSubmit}>
      <label>Username</label>
      <br />
      <input type="text" ref={nameRef} required />
      <br />
      <button type="submit">Submit</button>
    </form>
  );
}
