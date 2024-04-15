
#include "GetNmeaLoggerSentencesResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNmeaLoggerSentencesResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNmeaLoggerSentencesResult::CmdName = "GetNmeaLoggerSentencesResult";
    const char* const GetNmeaLoggerSentencesResult::Documentation = "Result of GetNmeaLoggerSentences.\n"
      "\n"
      "Name      Type         Description\n"
      "--------- ------------ -------------------------------------------------------------------------------------------------------\n"
      "Sentences array string Identifiers of the NMEA sentences to generate, only \"GGA\", \"GLL\", \"GSV\", \"RMC\" and \"ZDA\" are supported.";
    const char* const GetNmeaLoggerSentencesResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNmeaLoggerSentencesResult);


    GetNmeaLoggerSentencesResult::GetNmeaLoggerSentencesResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNmeaLoggerSentencesResult::GetNmeaLoggerSentencesResult(const std::vector<std::string>& sentences)
      : CommandResult(CmdName, TargetId)
    {

      setSentences(sentences);
    }

    GetNmeaLoggerSentencesResult::GetNmeaLoggerSentencesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& sentences)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSentences(sentences);
    }


    GetNmeaLoggerSentencesResultPtr GetNmeaLoggerSentencesResult::create(const std::vector<std::string>& sentences)
    {
      return std::make_shared<GetNmeaLoggerSentencesResult>(sentences);
    }

    GetNmeaLoggerSentencesResultPtr GetNmeaLoggerSentencesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& sentences)
    {
      return std::make_shared<GetNmeaLoggerSentencesResult>(relatedCommand, sentences);
    }

    GetNmeaLoggerSentencesResultPtr GetNmeaLoggerSentencesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNmeaLoggerSentencesResult>(ptr);
    }

    bool GetNmeaLoggerSentencesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Sentences"])
        ;

    }

    std::string GetNmeaLoggerSentencesResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNmeaLoggerSentencesResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Sentences"}; 
      return names; 
    }


    std::vector<std::string> GetNmeaLoggerSentencesResult::sentences() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Sentences"]);
    }

    void GetNmeaLoggerSentencesResult::setSentences(const std::vector<std::string>& sentences)
    {
      m_values.AddMember("Sentences", parse_json<std::vector<std::string>>::format(sentences, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
