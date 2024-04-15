
#include "GetAllMerkleTreeID.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMerkleTreeID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMerkleTreeID::CmdName = "GetAllMerkleTreeID";
    const char* const GetAllMerkleTreeID::Documentation = "Get Get all OSNMA Merkle Trees unique identifiers.";
    const char* const GetAllMerkleTreeID::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllMerkleTreeID);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMerkleTreeID);


    GetAllMerkleTreeID::GetAllMerkleTreeID()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetAllMerkleTreeIDPtr GetAllMerkleTreeID::create()
    {
      return std::make_shared<GetAllMerkleTreeID>();
    }

    GetAllMerkleTreeIDPtr GetAllMerkleTreeID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMerkleTreeID>(ptr);
    }

    bool GetAllMerkleTreeID::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAllMerkleTreeID::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllMerkleTreeID::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAllMerkleTreeID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
