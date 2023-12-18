#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNmeaLoggerSentences.
    ///
    /// Name      Type         Description
    /// --------- ------------ -------------------------------------------------------------------------------------------------------
    /// Sentences array string Identifiers of the NMEA sentences to generate, only "GGA", "GLL", "GSV", "RMC" and "ZDA" are supported.
    ///

    class GetNmeaLoggerSentencesResult;
    typedef std::shared_ptr<GetNmeaLoggerSentencesResult> GetNmeaLoggerSentencesResultPtr;
    
    
    class GetNmeaLoggerSentencesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNmeaLoggerSentencesResult();

      GetNmeaLoggerSentencesResult(const std::vector<std::string>& sentences);

      GetNmeaLoggerSentencesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& sentences);

      static GetNmeaLoggerSentencesResultPtr create(const std::vector<std::string>& sentences);

      static GetNmeaLoggerSentencesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& sentences);
      static GetNmeaLoggerSentencesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** sentences ****
      std::vector<std::string> sentences() const;
      void setSentences(const std::vector<std::string>& sentences);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetNmeaLoggerSentencesResult);
  }
}

