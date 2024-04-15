#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetOsnmaTagSize.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------
    /// TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.
    ///

    class GetOsnmaTagSizeResult;
    typedef std::shared_ptr<GetOsnmaTagSizeResult> GetOsnmaTagSizeResultPtr;
    
    
    class GetOsnmaTagSizeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaTagSizeResult();

      GetOsnmaTagSizeResult(int tagSize);

      GetOsnmaTagSizeResult(CommandBasePtr relatedCommand, int tagSize);

      static GetOsnmaTagSizeResultPtr create(int tagSize);

      static GetOsnmaTagSizeResultPtr create(CommandBasePtr relatedCommand, int tagSize);
      static GetOsnmaTagSizeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** tagSize ****
      int tagSize() const;
      void setTagSize(int tagSize);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaTagSizeResult);
  }
}

