#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------
    /// Index int    Coefficient index [1..9]
    /// Val   double Coefficient value
    ///

    class SetIonoBdgimAlpha;
    typedef std::shared_ptr<SetIonoBdgimAlpha> SetIonoBdgimAlphaPtr;
    
    
    class SetIonoBdgimAlpha : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIonoBdgimAlpha();

      SetIonoBdgimAlpha(int index, double val);

      static SetIonoBdgimAlphaPtr create(int index, double val);
      static SetIonoBdgimAlphaPtr dynamicCast(CommandBasePtr ptr);
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

