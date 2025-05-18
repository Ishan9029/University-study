import React from 'react';
import useCounter from './useCounter';
function CounterComponent() {
  const { count, increment, decrement, reset } = useCounter(0);
  return (
    <div>
      <h2>Count: {count}</h2>
      <button onClick={increment}>+1</button>
      <button onClick={reset}>reset</button>
      <button onClick={decrement}>-1</button>
    </div>
  );
}
export default CounterComponent;
