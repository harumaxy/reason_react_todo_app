open Action;

let str = ReasonReact.string;

let emptyPattern = {|^(\s)*$|};
let is_empty = Revamp.test(emptyPattern);

[@react.component]
let make = (~dispatch) => {
  let (todoText, setTodoText) = React.useState(() => "");
  <form
    className="todoInputForm"
    onSubmit={e => {
      e->ReactEvent.Form.preventDefault;
      setTodoText(_ => "");
      if (is_empty(todoText)) {
        Js.log("empty!");
      } else {
        Add(todoText)->dispatch;
      };
    }}>
    <input
      value=todoText
      onChange={e => e->Utils.valueFromEvent->setTodoText}
    />
    <button type_="submit" onClick={_ => Js.log("hello")}>
      {React.string("Add")}
    </button>
  </form>;
};