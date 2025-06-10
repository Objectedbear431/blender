#include "node_shader_util.hh"

namespace blender::nodes::node_shader_custom_green_cc 
{
    static void node_declare(NodeDeclarationBuilder& b)
    {
        b.add_input<decl::Float>("Factor").min(0.0f).max(1.0f).default_value(1.0f);
        b.add_input<decl::Float>("Saturation").min(0.0f).max(2.0f).default_value(1.0f);
        b.add_output<decl::Color>("Color");
    }

    static int node_shader_gpu_custom_green(GPUMaterial* mat,
        bNode* node,
        bNodeExecData* /*execdata*/,
        GPUNodeStack* in,
        GPUNodeStack* out)
    {
        return GPU_stack_link(mat, node, "node_shader_custom_green", in, out);
    }

}  // namespace blender::nodes::node_shader_custom_green_cc

void register_node_type_sh_custom_green()
{
    namespace file_ns = blender::nodes::node_shader_custom_green_cc;

    static bNodeType ntype;

    sh_node_type_base(&ntype, "ShaderNodeCustomGreen", SH_NODE_CUSTOM_GREEN);
    ntype.ui_name = "Custom Green";
    ntype.ui_description = "Outputs green color with adjustable saturation";
    ntype.nclass = NODE_CLASS_INPUT;

    ntype.declare = file_ns::node_declare;
    ntype.gpu_fn = file_ns::node_shader_gpu_custom_green;

    nodeRegisterType(&ntype);







}
