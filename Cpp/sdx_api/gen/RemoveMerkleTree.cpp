
#include "RemoveMerkleTree.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMerkleTree
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMerkleTree::CmdName = "RemoveMerkleTree";
    const char* const RemoveMerkleTree::Documentation = "Remove an OSNMA Merkle Tree.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------------------------------------\n"
      "Id   string Unique identifier of the Merkle Tree to remove.";
    const char* const RemoveMerkleTree::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveMerkleTree);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveMerkleTree);


    RemoveMerkleTree::RemoveMerkleTree()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveMerkleTree::RemoveMerkleTree(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    RemoveMerkleTreePtr RemoveMerkleTree::create(const std::string& id)
    {
      return std::make_shared<RemoveMerkleTree>(id);
    }

    RemoveMerkleTreePtr RemoveMerkleTree::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveMerkleTree>(ptr);
    }

    bool RemoveMerkleTree::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveMerkleTree::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveMerkleTree::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int RemoveMerkleTree::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveMerkleTree::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveMerkleTree::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
