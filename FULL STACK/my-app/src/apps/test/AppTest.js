import React, { useState } from 'react';
export default function App6() {
  const [count, setcount] = useState(0);
  return (
    <div>
      <h1>Count: {count}</h1>
      <button onClick={() => setcount(count - 1)}>Decrease</button>
      <button onClick={() => setcount(0)}>Reset</button>
      <button onClick={() => setcount(count + 1)}>Increase</button>
    </div>
  );
}
