open Todo;
open Action;

[@react.component]
let make = (~todo, ~dispatch) => {
  <div key={string_of_int(todo.id)} className="todoItem">
    <input
      type_="checkbox"
      className="completed"
      onChange={_ => {Toggle(todo.id)->dispatch}}
      value={string_of_bool(todo.completed)}
    />
    <span className="todoId"> {React.string(string_of_int(todo.id))} </span>
    <span className={"todoContent" ++ (todo.completed ? " strike" : "")}>
      {React.string(todo.text)}
    </span>
    {if (todo.completed) {
       <button
         className="delete-btn" onClick={_ => Delete(todo.id)->dispatch}>
         {React.string("Delete")}
       </button>;
     } else {
       <> </>;
     }}
  </div>;
};