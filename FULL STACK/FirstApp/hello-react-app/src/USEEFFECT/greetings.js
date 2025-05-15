import React from 'react';
function greeting(props) {
  return (
    <h1>
      Hello {props.name} {props.lname}
    </h1>
  );
}
export default greeting;
