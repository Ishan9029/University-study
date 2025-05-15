import { useState } from 'react';
function useCounter(initialvalue = 0) {
  const [count, setCount] = useState(initialvalue);
  const increment = () => setCount((prev) => prev + 1);
  const reset = () => setCount(initialvalue);
  const decrement = () => setCount((prev) => prev - 1);
  return { count, increment, reset, decrement };
}

export default useCounter;
