
#include "GetAllSignalsFromIntTxResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSignalsFromIntTxResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSignalsFromIntTxResult::CmdName = "GetAllSignalsFromIntTxResult";
    const char* const GetAllSignalsFromIntTxResult::Documentation = "Result of GetAllSignalsFromIntTx.\n"
      "\n"
      "Name      Type         Description\n"
      "--------- ------------ -----------------------------------------------------\n"
      "Id        string       Transmitter unique identifier.\n"
      "IdsSignal array string List of signal ID for this interferences transmitter.";
    const char* const GetAllSignalsFromIntTxResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSignalsFromIntTxResult);


    GetAllSignalsFromIntTxResult::GetAllSignalsFromIntTxResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllSignalsFromIntTxResult::GetAllSignalsFromIntTxResult(const std::string& id, const std::vector<std::string>& idsSignal)
      : CommandResult(CmdName, TargetId)
    {

      setId(id);
      setIdsSignal(idsSignal);
    }

    GetAllSignalsFromIntTxResult::GetAllSignalsFromIntTxResult(CommandBasePtr relatedCommand, const std::string& id, const std::vector<std::string>& idsSignal)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setId(id);
      setIdsSignal(idsSignal);
    }


    GetAllSignalsFromIntTxResultPtr GetAllSignalsFromIntTxResult::create(const std::string& id, const std::vector<std::string>& idsSignal)
    {
      return std::make_shared<GetAllSignalsFromIntTxResult>(id, idsSignal);
    }

    GetAllSignalsFromIntTxResultPtr GetAllSignalsFromIntTxResult::create(CommandBasePtr relatedCommand, const std::string& id, const std::vector<std::string>& idsSignal)
    {
      return std::make_shared<GetAllSignalsFromIntTxResult>(relatedCommand, id, idsSignal);
    }

    GetAllSignalsFromIntTxResultPtr GetAllSignalsFromIntTxResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSignalsFromIntTxResult>(ptr);
    }

    bool GetAllSignalsFromIntTxResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["IdsSignal"])
        ;

    }

    std::string GetAllSignalsFromIntTxResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllSignalsFromIntTxResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "IdsSignal"}; 
      return names; 
    }


    std::string GetAllSignalsFromIntTxResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetAllSignalsFromIntTxResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetAllSignalsFromIntTxResult::idsSignal() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["IdsSignal"]);
    }

    void GetAllSignalsFromIntTxResult::setIdsSignal(const std::vector<std::string>& idsSignal)
    {
      m_values.AddMember("IdsSignal", parse_json<std::vector<std::string>>::format(idsSignal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
