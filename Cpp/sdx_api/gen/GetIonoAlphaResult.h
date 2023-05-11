#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoAlpha.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------
    /// Index int    Coefficient index [0..3]
    /// Val   double Coefficient value
    ///

    class GetIonoAlphaResult;
    typedef std::shared_ptr<GetIonoAlphaResult> GetIonoAlphaResultPtr;
    
    
    class GetIonoAlphaResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoAlphaResult();

      GetIonoAlphaResult(int index, double val);

      GetIonoAlphaResult(CommandBasePtr relatedCommand, int index, double val);

      static GetIonoAlphaResultPtr create(int index, double val);

      static GetIonoAlphaResultPtr create(CommandBasePtr relatedCommand, int index, double val);
      static GetIonoAlphaResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIonoAlphaResult);
  }
}

