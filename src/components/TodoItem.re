open Todo;

[@react.component]
let make = (~todo) => {
  <div key={string_of_int(todo.id)} className="todoItem">
    <input type_="checkbox" className="completed" />
    <span className="todoId"> {React.string(string_of_int(todo.id))} </span>
    <span className="todoContent"> {React.string(todo.text)} </span>
  </div>;
};