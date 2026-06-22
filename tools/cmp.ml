(* Compare two files or one file and stdin.
   Exit with 0 if identical, 1 if different.

   The two files being compared are opened in text mode, so that CRLF/LF
   differences are ignored on Windows.  This is the only difference
   with `cmp -s`. *)

let rec cmp ic1 ic2 =
  match input_char ic1 with
  | c1 ->
      begin match input_char ic2 with
      | c2 -> c1 = c2 && cmp ic1 ic2
      | exception End_of_file -> false
      end
  | exception End_of_file ->
      begin match input_char ic2 with
      | c2 -> false
      | exception End_of_file -> true
      end

let with_open filename fn =
  if filename = "-" then begin
    In_channel.set_binary_mode stdin false;
    fn stdin
  end else
    In_channel.with_open_text filename fn

let usage () =
  Printf.eprintf "Usage: cmp <file1> <file2>\nOne <file> can be '-' for standard output.\n";
  exit 2

let _ =
  if Array.length Sys.argv <> 3 then usage ();
  let same =
    with_open Sys.argv.(1) (fun ic1 ->
    with_open Sys.argv.(2) (fun ic2 -> cmp ic1 ic2)) in
  exit (if same then 0 else 1)
