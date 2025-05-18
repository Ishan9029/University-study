import React, { useState, useEffect } from 'react';

export default function App6() {
  const [count, setCount] = useState(0);
  useEffect(() => console.log(`count value is updated ${count}`), [count]);
  return (
    <div>
      <h2>Count: {count}</h2>
      <button onClick={() => setCount(count - 1)}>Decrease</button>
      <button onClick={() => setCount(0)}>Reset</button>
      <button onClick={() => setCount(count + 1)}>Increase</button>
    </div>
  );
}
