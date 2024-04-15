#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the GPS ionospheric Alpha coefficient
    /// Alpha 0 is in seconds
    /// Alpha 1 is in seconds/semicircle
    /// Alpha 2 is in seconds/semicircle^2
    /// Alpha 3 is in seconds/semicircle^3
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------
    /// Index int    Coefficient index [0..3]
    /// Val   double Coefficient value
    ///

    class SetIonoAlpha;
    typedef std::shared_ptr<SetIonoAlpha> SetIonoAlphaPtr;
    
    
    class SetIonoAlpha : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIonoAlpha();

      SetIonoAlpha(int index, double val);

      static SetIonoAlphaPtr create(int index, double val);
      static SetIonoAlphaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
    
  }
}

