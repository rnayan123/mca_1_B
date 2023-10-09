// App.js
import React, { useState, useEffect } from "react";
import TaskList from "./components/TaskList";
import TaskForm from "./components/TaskForm";
import {
  loadTasksFromLocalStorage,
  saveTasksToLocalStorage,
} from "./localStorage";
import "./App.css"; // Import the CSS file

function App() {
  const [tasks, setTasks] = useState(loadTasksFromLocalStorage());
  const [taskToEdit, setTaskToEdit] = useState(null);

  useEffect(() => {
    saveTasksToLocalStorage(tasks);
  }, [tasks]);

  const addTask = (newTask) => {
    if (taskToEdit !== null) {
      const updatedTasks = [...tasks];
      updatedTasks[taskToEdit] = newTask;
      setTasks(updatedTasks);
      setTaskToEdit(null);
    } else {
      setTasks([...tasks, newTask]);
    }
  };

  const editTask = (index) => {
    setTaskToEdit(index);
  };

  const deleteTask = (index) => {
    const updatedTasks = [...tasks];
    updatedTasks.splice(index, 1);
    setTasks(updatedTasks);
  };

  return (
    <div className="grid-container">
      <h2>T A S K - M A N A G E R</h2><br></br>
      <TaskForm
        onSubmit={addTask}
        taskToEdit={taskToEdit !== null ? tasks[taskToEdit] : null}
      />
      <TaskList tasks={tasks} onDelete={deleteTask} onEdit={editTask} />
    </div>
  );
}

export default App;
