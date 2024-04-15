
#include "GetAllMerkleTreeIDResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMerkleTreeIDResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMerkleTreeIDResult::CmdName = "GetAllMerkleTreeIDResult";
    const char* const GetAllMerkleTreeIDResult::Documentation = "Result of GetAllMerkleTreeID.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ ----------------------------------------\n"
      "Ids  array string Array of Merkle Trees unique identifiers";
    const char* const GetAllMerkleTreeIDResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMerkleTreeIDResult);


    GetAllMerkleTreeIDResult::GetAllMerkleTreeIDResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllMerkleTreeIDResult::GetAllMerkleTreeIDResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetAllMerkleTreeIDResult::GetAllMerkleTreeIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIds(ids);
    }


    GetAllMerkleTreeIDResultPtr GetAllMerkleTreeIDResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMerkleTreeIDResult>(ids);
    }

    GetAllMerkleTreeIDResultPtr GetAllMerkleTreeIDResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMerkleTreeIDResult>(relatedCommand, ids);
    }

    GetAllMerkleTreeIDResultPtr GetAllMerkleTreeIDResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMerkleTreeIDResult>(ptr);
    }

    bool GetAllMerkleTreeIDResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllMerkleTreeIDResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllMerkleTreeIDResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


    std::vector<std::string> GetAllMerkleTreeIDResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllMerkleTreeIDResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
