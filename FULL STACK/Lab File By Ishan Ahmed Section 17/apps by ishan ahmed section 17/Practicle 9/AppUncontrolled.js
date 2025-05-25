import React from 'react';

export default function App4() {
  const handleSubmit = (event) => {
    event.preventDefault();
  };

  return (
    <div>
      <h1>This is Uncontrolled Component</h1>
      <form onSubmit={handleSubmit}>
        <br />
        <input type="text" required maxLength={16} placeholder="Username" />
        <br />
        <input type="password" required minLength={8} placeholder="Password" />
        <br />
        <button type="submit">Submit</button>
      </form>
    </div>
  );
}
