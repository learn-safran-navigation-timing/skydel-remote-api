
#include "GetMerkleTreeParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMerkleTreeParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMerkleTreeParameters::CmdName = "GetMerkleTreeParameters";
    const char* const GetMerkleTreeParameters::Documentation = "Get Merkle Tree parameters.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------------------------------------------------------------\n"
      "Id   string Merkle Tree unique identifier. Automatically set for new Merkle Trees.";
    const char* const GetMerkleTreeParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMerkleTreeParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMerkleTreeParameters);


    GetMerkleTreeParameters::GetMerkleTreeParameters()
      : CommandBase(CmdName, TargetId)
    {}

    GetMerkleTreeParameters::GetMerkleTreeParameters(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMerkleTreeParametersPtr GetMerkleTreeParameters::create(const std::string& id)
    {
      return std::make_shared<GetMerkleTreeParameters>(id);
    }

    GetMerkleTreeParametersPtr GetMerkleTreeParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMerkleTreeParameters>(ptr);
    }

    bool GetMerkleTreeParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMerkleTreeParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMerkleTreeParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMerkleTreeParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMerkleTreeParameters::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMerkleTreeParameters::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
