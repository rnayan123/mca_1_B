// TaskList.js
import React from "react";
import "./TaskList.css"; // Import a new CSS file for styling

const TaskList = ({ tasks, onDelete, onEdit }) => {
  return (
    <div>
      <ul className="task-list">
        {tasks.map((task, index) => (
          <li key={index} className="task-item">
            <div className="task-details">
              <strong className="task-name">{task.name}</strong>
              {task.description && (
                <p className="task-description">{task.description}</p>
              )}
            </div>
            <div className="task-buttons">
              <button onClick={() => onEdit(index)} className="edit-button">
                Edit
              </button>
              <button onClick={() => onDelete(index)} className="delete-button">
                Delete
              </button>
            </div>
          </li>
        ))}
      </ul>
    </div>
  );
};

export default TaskList;
