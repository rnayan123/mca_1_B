// TaskForm.js
import React, { useState, useEffect } from "react";

const TaskForm = ({ onSubmit, taskToEdit }) => {
  const [task, setTask] = useState(taskToEdit || { name: "", description: "" });

  useEffect(() => {
    setTask(taskToEdit || { name: "", description: "" });
  }, [taskToEdit]);

  const handleSubmit = (e) => {
    e.preventDefault();
    if (task.name.trim() === "" || task.description.trim() === "") {
      return; // Prevent submission if name or description is empty
    }
    onSubmit(task);
    setTask({ name: "", description: "" });
  };

  return (
    <form onSubmit={handleSubmit}>
      <div className="mb-3">
        <center>
          <label htmlFor="taskName" className="form-label">
            Task Name
          </label>
        </center>
        <input
          type="text"
          className="form-control"
          id="taskName"
          value={task.name}
          onChange={(e) => setTask({ ...task, name: e.target.value })}
        />
      </div>
      <br></br>
      <div className="mb-3">
        <center>
          <label htmlFor="taskDescription" className="form-label">
            Task Description
          </label>
        </center>
        <textarea
          className="form-control"
          id="taskDescription"
          value={task.description}
          onChange={(e) => setTask({ ...task, description: e.target.value })}
        />
      </div>
      <br></br>
      <button id="any"
        type="submit"
        className={taskToEdit ? "edit-button" : "add-button"}
      >
        {taskToEdit ? "Edit Task" : "Add Task"}
      </button>
      <br></br>
    </form>
  );
};

export default TaskForm;
