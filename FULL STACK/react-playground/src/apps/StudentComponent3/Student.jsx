import React from 'react';
const Student = (props) => {
  return (
    <div>
      {/* Display Students name in an <h2> element */}
      <h2>{props.name}</h2>
      <p>Grade : {props.grade}</p>
    </div>
  );
};
export default Student;
