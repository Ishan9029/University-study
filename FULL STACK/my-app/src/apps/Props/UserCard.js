import React from 'react';

export default function UserCard(props) {
  return (
    <div>
      <h2>{props.username}</h2>
      <p>Age : {props.age}</p>
      <p>city : {props.city}</p>
    </div>
  );
}
