#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command QzssPerturbations is deprecated since 20.9. You may use Perturbations.
    /// 
    /// Set QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------
    /// SvId int    Satellite SV ID 1..10
    /// Crs  double Crs (meter)
    /// Crc  double Crc (meter)
    /// Cis  double Crs (rad)
    /// Cic  double Crc (rad)
    /// Cus  double Cus (rad)
    /// Cuc  double Cuc (rad)
    ///

    class SetQzssPerturbations;
    typedef std::shared_ptr<SetQzssPerturbations> SetQzssPerturbationsPtr;
    
    
    class SetQzssPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssPerturbations();

      SetQzssPerturbations(int svId, double crs, double crc, double cis, double cic, double cus, double cuc);
  
      static SetQzssPerturbationsPtr create(int svId, double crs, double crc, double cis, double cic, double cus, double cuc);
      static SetQzssPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** crs ****
      double crs() const;
      void setCrs(double crs);


      // **** crc ****
      double crc() const;
      void setCrc(double crc);


      // **** cis ****
      double cis() const;
      void setCis(double cis);


      // **** cic ****
      double cic() const;
      void setCic(double cic);


      // **** cus ****
      double cus() const;
      void setCus(double cus);


      // **** cuc ****
      double cuc() const;
      void setCuc(double cuc);
    };
  }
}

