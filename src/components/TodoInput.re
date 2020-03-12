open Action;

let str = ReasonReact.string;

[@react.component]
let make = (~dispatch) => {
  let (todoText, setTodoText) = React.useState(() => "");
  <form
    className="todoInputForm"
    onSubmit={e => {
      e->ReactEvent.Form.preventDefault;
      setTodoText(_ => "");
      Add(todoText)->dispatch;
    }}>
    <input
      value=todoText
      onChange={e => e->Utils.valueFromEvent->setTodoText}
    />
    <button type_="submit" onClick={_ => Js.log("hello")}>
      {React.string("add")}
    </button>
  </form>;
};