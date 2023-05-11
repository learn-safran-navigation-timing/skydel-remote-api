
#include "gen/GetIntTxPersistenceResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxPersistenceResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxPersistenceResult::CmdName = "GetIntTxPersistenceResult";
    const char* const GetIntTxPersistenceResult::Documentation = "Result of GetIntTxPersistence.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxPersistenceResult);


    GetIntTxPersistenceResult::GetIntTxPersistenceResult()
      : CommandResult(CmdName)
    {}

    GetIntTxPersistenceResult::GetIntTxPersistenceResult(bool persistence, const std::string& id)
      : CommandResult(CmdName)
    {

      setPersistence(persistence);
      setId(id);
    }

    GetIntTxPersistenceResult::GetIntTxPersistenceResult(CommandBasePtr relatedCommand, bool persistence, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPersistence(persistence);
      setId(id);
    }


    GetIntTxPersistenceResultPtr GetIntTxPersistenceResult::create(bool persistence, const std::string& id)
    {
      return std::make_shared<GetIntTxPersistenceResult>(persistence, id);
    }

    GetIntTxPersistenceResultPtr GetIntTxPersistenceResult::create(CommandBasePtr relatedCommand, bool persistence, const std::string& id)
    {
      return std::make_shared<GetIntTxPersistenceResult>(relatedCommand, persistence, id);
    }

    GetIntTxPersistenceResultPtr GetIntTxPersistenceResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxPersistenceResult>(ptr);
    }

    bool GetIntTxPersistenceResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Persistence"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxPersistenceResult::documentation() const { return Documentation; }


    bool GetIntTxPersistenceResult::persistence() const
    {
      return parse_json<bool>::parse(m_values["Persistence"]);
    }

    void GetIntTxPersistenceResult::setPersistence(bool persistence)
    {
      m_values.AddMember("Persistence", parse_json<bool>::format(persistence, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxPersistenceResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxPersistenceResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
