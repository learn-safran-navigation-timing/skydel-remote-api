#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the GPS ionospheric Alpha coefficient
    /// Alpha 0 is in seconds
    /// Alpha 1 is in seconds/semicircle
    /// Alpha 2 is in seconds/semicircle^2
    /// Alpha 3 is in seconds/semicircle^3
    ///
    /// Name  Type Description
    /// ----- ---- ------------------------
    /// Index int  Coefficient index [0..3]
    ///

    class GetIonoAlpha;
    typedef std::shared_ptr<GetIonoAlpha> GetIonoAlphaPtr;
    
    
    class GetIonoAlpha : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoAlpha();

      GetIonoAlpha(int index);

      static GetIonoAlphaPtr create(int index);
      static GetIonoAlphaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);
    };
    
  }
}

