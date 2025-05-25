import React from 'react';
import UserCard from './UserCard';

export default function AppProps() {
  return (
    <div>
      <UserCard username="John" age={25} city="New York" />
      <br />
      <UserCard username="Emily" age={30} city="London" />
    </div>
  );
}
