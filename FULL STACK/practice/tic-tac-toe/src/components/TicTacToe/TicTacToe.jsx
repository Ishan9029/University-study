import React from "react";
import "./TicTacToe.css";
import circle_icon from "./com";
import cross_icon from "C:UsersASUSOneDriveDocumentsCODINGFULL STACKpractice\tic-tac-toesrccomponentsassetscross.png";
const TicTacToe = () => {
  return (
    <div className="container">
      <h1 classname="title">
        Tic Tac Toe Game In <span>React</span>
      </h1>
      <div className="board"></div>
      <button className="reset">Reset</button>
    </div>
  );
};

export default TicTacToe;
