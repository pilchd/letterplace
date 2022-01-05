import {nodeResolve} from "@rollup/plugin-node-resolve";


export default {
    input: "letter/app.js",
    output: {
        file: "letter_dist/scripts/bundle.js",
        sourcemap: "inline",
        format: "iife"
    },
    plugins: [nodeResolve()]
};
